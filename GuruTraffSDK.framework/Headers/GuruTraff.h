//
//  GuruTraff.h
//  GuruTraffSDK
//
//  Copyright © 2018 GuruTraff. All rights reserved.


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GuruTraffDelegate.h"

@interface GuruTraff : NSObject

-(GuruTraff*) init NS_UNAVAILABLE;

+(void) initializeWithAppId: (NSString*) appId;

+(void) setAppUserId:(NSString*) gameUserId;


+(void) showVideo: (NSString*) placementName;

+(BOOL) isReadyVideo: (NSString*) placementName;

+(void) cacheVideo: (NSString*) placementName;


+(id<GuruTraffDelegate>) delegate;

+(void) setDelegate:(id<GuruTraffDelegate>)delegate;

+(void) purchaseEvent:(double) price andCurrency:(NSString*) currency andTransactionId:(NSString*) transactionId;

+(void) requestMotivatedRewards;

+(void) removeMotivatedRewards:(NSArray<NSString* >* _Nonnull) rewardIds;

+(void)logEnable:(BOOL) enable;

@end
