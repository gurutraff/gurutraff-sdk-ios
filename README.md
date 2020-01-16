
# GuruTraff SDK for iOS

## Builds
Builds can be found from the [releases page](https://github.com/gurutraff/gurutraff-sdk-ios/releases).

## Minimum Requirements:
    - iOS 8 or higher.

## Integration steps

### Step 1: Import GuruTraffSDK.framework into the project.

    To import a framework into the project do the following:
    
- In the "Project navigator" select the necessary project 
- Select the necessary Target from the list of available
- Select the "General" tab
- Add the GuruTraffSDK.framework framework to the "Embedded Binaries" list

### Step 2: Initialize the GuruTraff SDK in code.
    
Import the framework:

    #import <GuruTraffSDK/GuruTraffSDK.h>

To initialize the GuruTraff SDK, you need to call in your code:

    [GuruTraff initializeWithAppId:@"YOUR_APP_ID"];
    
We also recommend setting the player ID according to your backend server version. To do this, call:

    [GuruTraff setAppUserId:@"YOUR_USER_ID"];

AppUserId will be passed on from the ad server to your pre-registered server to reward the user for viewing the advertisements.

If you have in-app purchases, you must send them using the following method:
purchaseEvent:(double) price andCurrency:(NSString*) currency andTransactionId:(NSString*) transactionId
Example:

    [GuruTraff purchaseEvent:0.99 andCurrency:@"USD" andTransactionId:@"YOUR_TRANSACTION_ID"];

### Step 3: Showing advertising

a) We recommend to pre-cache ads using the method:
	

    [GuruTraff cacheVideo:@"placementName"];

b) You can check whether cached ads are available using the method:
	

    [GuruTraff isReadyVideo:@"placementName"];

c) You can show ads using the method:
	

    [GuruTraff showVideo:@"placementName"];

d) You can subscribe to the events with help of GuruTraffDelegate protocol, this way you can track changes in the advertising states (conditions)

- videoDidCache;			          //resources were cached for displaying video ads
- videoDidFailToLoad;        	    	//error loading video ads
- videoWindowWillDisplay;		      //called before opening the advertisement window
- videoWindowDidDisplay; 			  //called after the advertisement window was opened on the screen
- videoDidDismiss;			          //after hiding the video, the post image is shown
- videoWindowWillClose;			      //called before closing the advertising window
- videoWindowDidClose;			      //called after the advertisement window was closed
- videoPostViewDidClick;              //player clicked on the ads
- videoReceiveReward;                 //player can be rewarded for successfully watching video ads

Possible errors loading ads:
- GTRequestErrorNoAds - no ads available
- GTRequestErrorNoFreeSpace - there is no space on the disk
- NoConnectionToServer - no connection to our server
        
Note:
It is possible not to cache the advertisement in advance, but in this case, it is impossible to predict when it will be loaded and displayed.
Before showing ads, you need to pause all the sounds in the game.

### Step 4: Done!

Now you can show ads in your application.



### (Optional) Reward users on install

To improve the score of the traffic, we recommend rewarding players for installing the advertised games.
With our API you can get the necessary information to reward the player with virtual currency (such as crystals, coins...)

To request the information regarding the reward when starting the game and after switching from the background to the active mode, we recommend calling the method:

    [GuruTraff requestMotivatedRewards];

You can process the received information in the methods of the GuruTraffDelegate protocol:
- receiveMotivatedRewards: In case of receiving successful information from the server
- failedRequestMotivatedRewards: In case of an error

In the receiveMotivatedRewards method, you receive an array of data NSArray<GTMotivatedRewardInfo*>, where each element contains:
- rewardId - reward identifier
- appName - the name of the installed application
- amountOfReward - the amount of virtual currency that needs to be credited to the player

The handler returns a bool value, where true - automatically remove received rewards from the GuruTraff server, false - if you want to remove it manually.

If your reward handler returns false, you need to manually call the method 
		

    [GuruTraff removeMotivatedRewards:rewardIdsToRemove];
   where rewardIdsToRemove is an array of reward identifiers received in receiveMotivatedRewards.

For the rewards to work correctly, it is necessary to install AppUserId - the user ID on your server, before requesting advertising, if this is not done the users' motivation will not work.
