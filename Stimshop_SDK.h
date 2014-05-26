//
//  Stimshop_SDK.h
//  Stimshop_SDK
//
//  Created by Seb Jallot on 20/11/13.
//  Copyright (c) 2013 STIMShop. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol StimshopProtocol <NSObject>

@optional
- (void) didDetectWavWithCode:(NSString *)code;
- (void) didStopDetecting;

@end

@interface Stimshop_SDK : NSObject

@property (nonatomic, weak) id <StimshopProtocol> delegate;

+ (instancetype) takeoffWithAPIKey:(NSString *)APIkey;
+ (Stimshop_SDK *)sharedInstance ;

-(BOOL) isListening;
- (void) startListener;
- (void) stopListener;
- (BOOL) isDetecting; //Return true if the sound is currently detected
@end
