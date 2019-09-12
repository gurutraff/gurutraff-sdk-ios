//
//  GTRequestError.h
//  GuruTraffSDK
//
//  Copyright © 2018 GuruTraff. All rights reserved.

#ifndef GTRequestError_h
#define GTRequestError_h

typedef NS_ENUM(NSUInteger, GTRequestError) {
    GTRequestErrorNone = 0,
    GTRequestErrorNoAds = 1,
    GTRequestErrorNoFreeSpace = 2,
    GTRequestErrorNoConnectionToServer = 3,
    GTRequestErrorInternalError = 4,
    
    
};

#endif /* GTRequestError_h */
