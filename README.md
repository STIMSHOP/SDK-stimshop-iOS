# SDK-Stimshop-iOS

This SDK implements Stimshop's signal detection protocol.

## Installation of the SDK

### Import the files to your xcode project

Import the header file **StimshopSDK.h** and the library file **libStimshop_SDK.a** and **signal.momd** (remove .mom extension) into your iOS application project.
(Don't forget to add iOS frameworks amongs them : Coredata, AudioToolbox, AVFoundation, SystemConfiguration and Accelerate)

### Set your Info.plist file

Import our **Info.plist** file in order to allow your application to use the microphone and connect to our API.

### Import Headers

Add #import \<Foundation/Foundation.h>\ and #import "StimshopSDK.h" to your header file

### Configure your API key

We assume you already have your API key, allowing you to use Stimshop services.

## Initialization of the SDK

1. Initialize the SDK by calling the `takeOffWithAPIKey:` method on the StimshopSDK singleton :

        [[StimshopSDK sharedInstance] takeOffWithAPIKey:@"STIMSHOP-APIKEY"];

    Where `STIMSHOP-APIKEY` is the API key provided by Stimshop.

2. Choose the frequency channels to work with and to listen to by calling the `setActivatedChannels:` method on the StimshopSDK singleton, with the proper bitmask :

        [[StimshopSDK sharedInstance] setActivatedChannels:channelOne]; // Activates channel 1

        [[StimshopSDK sharedInstance] setActivatedChannels:channelTwo|channelThree]; // Activates channel 2 and 3
    
        [[StimshopSDK sharedInstance] setActivatedChannels:channelOne|channelTwo|channelThree]; // Activates all channels

    Here are the frequencies related to the channels :
    + channelOne : from 17kHz to 18kHz
    + channelTwo : from 18kHz to 19kHz
    + channelThree : from 19kHz to 20kHz
    
## Use of the SDK

### Set the delegate

In the class you want to use to perform signal detection, declare the delegate which will implement the `StimshopDelegate` protocol, by calling the `setDelegate:` method on the SimshopSDK singleton :

    [[StimshopSDK sharedInstance] setDelegate:self]; 
    /* Use self if the delegate is an instance of the class in which you want the signal
     * detection to be performed.
     */

### Implement the `StimshopDelegate` protocol methods

1. Required methods 

    + `didDetectWavWithCode:` is called whenever a correct and authorized code has been detected in the sound signal :

                /*! Called when a correct code has been detected in the sound signal
                 * \param code The detected code
                 */
                - (void)didDetectWavWithCode:(NSString *)code {
                        NSLog(@"CODE DETECTED : %@", code);
                }

    + `didStopWithErrorMessage:` is called when an error occurred during takeoff :

                /*! Called when an error occurred during take off.
                 * \param message The corresponding error message
                 */
                - (void)didStopWithErrorMessage:(NSString *)message {
                        NSLog(@"AN ERROR OCCURRED : %@", message);
                }

        Here are the two possible error messages :
        + `stimshopErrorInvalidAPIKey` : "API key is not valid anymore, starting canceled"
        + `stimshopErrorInvalidID` : "Invalid ID, starting canceled"

2. Optional methods

    + `didStopDetecting` is called when the SDK stopped listening to signals :

                /*! Called when the SDK stopped listening to signals
                 */
                - (void)didStopDetecting {
                        // Do something
                }

    + `didReceiveWinUrl:` is called whenever the detected code is related to an asset :

                /*! Called when the detected code is corresponding to an asset url
                 * \param url The string representing the url of the asset
                 */
                - (void)didReceiveWinUrl:(NSString *)url {
                        NSLog(@"ASSET URL : %@", url);
                }

### Everything's now ready, let's start detecting !

The SDK can start listening to signals by calling the `startListener` method on the StimshopSDK singleton :

    [[Stimshop_SDK sharedInstance] startListener];

When done, the SDK can be stopped by calling the `stopListener` method on the StimshopSDK singleton :

    [[Stimshop_SDK sharedInstance] stopListener];

The `isListening` method notifies whether the SDK is listening to signal or not.

The `isDetecting` method notifies whether the SDK has detected a correct code.

## For an example, feel free to check out the [Stimshop demo app](https://github.com/STIMSHOP/SDK-demo-iOS)

