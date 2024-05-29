
#ifndef SJWatermarkViewDefines_h
#define SJWatermarkViewDefines_h

#import <UIKit/UIKit.h>
#import "SJVideoPlayerPlaybackControllerDefines.h"

@protocol SJWatermarkView <NSObject>

- (void)layoutWatermarkInRect:(CGRect)rect videoPresentationSize:(CGSize)vSize videoGravity:(SJVideoGravity)videoGravity;

@end

#endif /* SJWatermarkViewDefines_h */