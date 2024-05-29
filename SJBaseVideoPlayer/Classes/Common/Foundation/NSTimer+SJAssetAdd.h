
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSTimer (SJAssetAdd)
+ (NSTimer *)sj_timerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats;
+ (NSTimer *)sj_timerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats usingBlock:(void(^_Nullable)(NSTimer *timer))usingBlock;

@property (nonatomic, copy, nullable) void (^sj_usingBlock)(NSTimer *timer);

- (void)sj_fire;
@end


@interface NSTimer (SJDeprecated)
+ (NSTimer *)assetAdd_timerWithTimeInterval:(NSTimeInterval)ti
                                      block:(void(^)(NSTimer *timer))block
                                    repeats:(BOOL)repeats;
- (void)assetAdd_fire;
@end
NS_ASSUME_NONNULL_END