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
- (void)videoDidCache:(NSString*)placementId;

/// Called after an Video has attempted to load
/// from the servers but failed.
- (void)videoDidFailToLoad:(NSString *)placementId
                 withError:(GTRequestError)error;

/// Called before an Video will be displayed on the screen.
- (void)videoWindowWillDisplay:(NSString*)placementId;

/// Called after an Video has been displayed on the screen.
- (void)videoWindowDidDisplay:(NSString*)placementId;

/// Called after an Video has been dismissed.
- (void)videoDidDismiss:(NSString*)placementId;

- (void)videoWindowWillClose:(NSString*)placementId;

/// Called after an Video has been closed.
- (void)videoWindowDidClose:(NSString*)placementId;

/// Called after an Video has been clicked.
- (void)videoPostViewDidClick:(NSString*)placementId;

- (void)videoReceiveReward:(NSString*) placementId;

#pragma mark - Motivated Reward

- (bool) receiveMotivatedRewards:(NSArray<GTMotivatedRewardInfo*>*) rewards;

- (void) failedRequestMotivatedRewards:(GTRequestError)error;

@end
