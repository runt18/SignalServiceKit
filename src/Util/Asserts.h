//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef OWSAssert

#ifdef DEBUG

#define USE_ASSERTS

#define CONVERT_TO_STRING(X) #X
#define CONVERT_EXPR_TO_STRING(X) CONVERT_TO_STRING(X)

#define OWSAssert(X) \
if (!(X)) { \
NSLog(@"Assertion failed: %s", CONVERT_EXPR_TO_STRING(X)); \
NSAssert(0, @"Assertion failed: %s", CONVERT_EXPR_TO_STRING(X)); \
}

// OWSAssert() should be used in Obj-C and Swift methods.
// OWSCAssert() should be used in free functions.
#define OWSCAssert(X) \
if (!(X)) { \
NSLog(@"Assertion failed: %s", CONVERT_EXPR_TO_STRING(X)); \
NSCAssert(0, @"Assertion failed: %s", CONVERT_EXPR_TO_STRING(X)); \
}

#else

// In production, we don't want asserts to fire.
// NS_BLOCK_ASSERTIONS should be set for Release builds, but
// we use a separate version of the macro to be safe.

#define OWSAssert(X)                                                                                                   \
    if (!(X)) {                                                                                                        \
        NSLog(@"Assertion failed: %s", CONVERT_EXPR_TO_STRING(X));                                                     \
    }

// OWSAssert() should be used in Obj-C and Swift methods.
// OWSCAssert() should be used in free functions.
#define OWSCAssert(X)                                                                                                  \
    if (!(X)) {                                                                                                        \
        NSLog(@"Assertion failed: %s", CONVERT_EXPR_TO_STRING(X));                                                     \
    }

#endif

#endif
