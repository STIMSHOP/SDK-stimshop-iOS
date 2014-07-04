//
//  StimshopSDK.h
//  stimshop_sdk
//
//  Created by William Archimede on 06/06/2014.
//  Copyright (c) 2014 STIMShop. All rights reserved.
//

@import Foundation;

static const NSString *stimshopErrorInvalidAPIKey = @"API key is not valid anymore, starting canceled";
static const NSString *stimshopErrorInvalidID = @"Invalid ID, starting canceled";

typedef enum : NSUInteger {
    channelOne = (1 << 0), // => 00000001, 17kHz<->18kHz
    channelTwo = (1 << 1), // => 00000010, 18kHz<->19kHz
    channelThree = (1 << 2), // => 00000100, 19kHz<->20kHz
    channelFour = (1 << 3) // => 00001000, 20kHz<->21kHz
} FrequencyChannel;

@protocol StimshopDelegate <NSObject>

@required
/*! Called when a correct code has been detected in the sound signal
 * \param code The detected code
 */
- (void)didDetectWavWithCode:(NSString *)code;
/*! Called when an error occurred during take off.
 * \param message The corresponding error message
 */
- (void)didStopWithErrorMessage:(NSString *)message;

@optional
/*! Called when the SDK stopped listening to signals
 */
- (void)didStopDetecting;
/*! Called when the detected code is corresponding to an asset url
 * \param url The string representing the url of the asset
 */
- (void)didReceiveWinUrl:(NSString *)url;
@end

@interface StimshopSDK : NSObject

@property (nonatomic, weak) id <StimshopDelegate> delegate;
@property (nonatomic, assign) FrequencyChannel activatedChannels;
@property (nonatomic, strong) NSMutableArray *channelsManagers;

+ (StimshopSDK *)sharedInstance;

- (void)takeOffWithAPIKey:(NSString *)APIKey;
- (void)startListener;
- (void)stopListener;
- (BOOL)isListening;
/*! Returns YES if the correct code is detected.
 */
- (BOOL)isDetecting;

@end


