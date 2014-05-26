Stimshop-ios-sdk
================

Ce SDK implémente le protocole de détection de signal Stimshop, 
Pour plus de détail voir le fichier Stimshop_SDK.h

### Installation

Importer les fichier Stimshop_SDK.h et libStimshop_SDK-Combined.a dans votre projet iOS.

 
### Utilisation 

Dans l'initialisation (AppDelegate ou initialisation de la classe)
 
	[Stimshop_SDK takeoffWithAPIKey:@"STS-012345"];

Où `STS-012345` est l'APIKey fournie par Stimshop
 
 
Ensuite dans la classe où est implémenté la détection :

	[[Stimshop_SDK sharedInstance] setDelegate:self];
	[[Stimshop_SDK sharedInstance] startListener];
 
Et les actions sont implémentées via le protocole :
 
	- (void) didDetectWavWithCode:(NSString)code{
		NSLog(@" Code détecté ! %@", code);
 	}

	- (void) didStopDetecting{
 
 	}


