//
//  GTMotivatedRewardInfo.h
//  GuruTraffApp
//
//  Created by Admin on 7/25/19.
//

#import <Foundation/Foundation.h>

@interface GTMotivatedRewardInfo : NSObject{
    @protected
    NSString* _rewardId;
    NSString* _appName;
    int _amountOfReward;
    
}

-(GTMotivatedRewardInfo*) initWithId:(NSString*) rewardId andName:(NSString*) appName andAmount:(int) amountOfReward;

@property (readonly) NSString* rewardId;
@property (readonly) NSString* appName;
@property (readonly) int amountOfReward;

@end

