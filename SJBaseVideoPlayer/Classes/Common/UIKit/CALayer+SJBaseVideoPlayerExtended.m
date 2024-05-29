
#import "CALayer+SJBaseVideoPlayerExtended.h"
#import <objc/message.h>

NS_ASSUME_NONNULL_BEGIN
@interface SJExtendedAnimationDelegate : NSObject<CAAnimationDelegate>
@property (nonatomic, copy, nullable) SJAnimationDidStartHandler startHandler;
@property (nonatomic, copy, nullable) SJAnimationDidStopHandler stopHandler;
@end

@implementation SJExtendedAnimationDelegate
- (void)animationDidStart:(CAAnimation *)anim {
    if ( _startHandler ) _startHandler(anim);
    _startHandler = nil;
}
- (void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag {
    if ( _stopHandler ) _stopHandler(anim, flag);
    _stopHandler = nil;
}
@end

@implementation CALayer (SJBaseVideoPlayerExtended)

- (void)pauseAnimation {
    CFTimeInterval pausedTime = [self convertTime:CACurrentMediaTime() fromLayer:nil];
    self.speed = 0.0;
    self.timeOffset = pausedTime;
}

- (void)resumeAnimation {
    CFTimeInterval pausedTime = [self timeOffset];
    self.speed = 1.0;
    self.timeOffset = 0.0;
    self.beginTime = 0.0;
    CFTimeInterval timeSincePause = [self convertTime:CACurrentMediaTime() fromLayer:nil] - pausedTime;
    self.beginTime = timeSincePause;
}

static void *defaultKey = &defaultKey;

- (void)addAnimation:(CAAnimation *)anim startHandler:(SJAnimationDidStartHandler)startHandler {
    [self addAnimation:anim startHandler:startHandler stopHandler:nil];
}

- (void)addAnimation:(CAAnimation *)anim stopHandler:(SJAnimationDidStopHandler)stopHandler {
    [self addAnimation:anim startHandler:nil stopHandler:stopHandler];
}


- (void)addAnimation:(CAAnimation *)anim startHandler:(nullable SJAnimationDidStartHandler)startHandler stopHandler:(nullable SJAnimationDidStopHandler)stopHandler {
    SJExtendedAnimationDelegate *delegate = objc_getAssociatedObject(self, defaultKey);
    if ( delegate == nil ) {
        delegate = SJExtendedAnimationDelegate.new;
        objc_setAssociatedObject(self, defaultKey, delegate, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    delegate.startHandler = startHandler;
    delegate.stopHandler = stopHandler;
    anim.delegate = delegate;
    [self addAnimation:anim forKey:nil];
}
@end
NS_ASSUME_NONNULL_END