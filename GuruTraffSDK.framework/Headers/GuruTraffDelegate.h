//
//  GuruTraffDelegate.h
//  GuruTraffSDK
//
//  Copyright © 2018 GuruTraff. All rights reserved.


#import <Foundation/Foundation.h>
#import "GTRequestError.h"
#import "GTMotivatedRewardInfo.h"

///Delegate methods for receiving AMBanner state changes
@protocol GuruTraffDelegate <NSObject>

@optional

#pragma mark - Video

/// Called after an Video has been loaded from the servers and cached locally.
- (void)videoDidCache:(NSString*)placementName;

/// Called after an Video has attempted to load
/// from the servers but failed.
- (void)videoDidFailToLoad:(NSString *)placementName
                 withError:(GTRequestError)error;

/// Called before an Video will be displayed on the screen.
- (void)videoWindowWillDisplay:(NSString*)placementName;

/// Called after an Video has been displayed on the screen.
- (void)videoWindowDidDisplay:(NSString*)placementName;

/// Called after an Video has been dismissed.
- (void)videoDidDismiss:(NSString*)placementName;

- (void)videoWindowWillClose:(NSString*)placementName;

/// Called after an Video has been closed.
- (void)videoWindowDidClose:(NSString*)placementName;

/// Called after an Video has been clicked.
- (void)videoPostViewDidClick:(NSString*)placementName;

- (void)videoReceiveReward:(NSString*) placementName;

#pragma mark - Motivated Reward

- (bool) receiveMotivatedRewards:(NSArray<GTMotivatedRewardInfo*>*) rewards;

- (void) failedRequestMotivatedRewards:(GTRequestError)error;

@end
