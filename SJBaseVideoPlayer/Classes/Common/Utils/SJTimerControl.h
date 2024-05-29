
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface SJTimerControl : NSObject

@property (nonatomic) NSTimeInterval interval;

@property (nonatomic, copy, nullable) void(^exeBlock)(SJTimerControl *control);

- (void)resume;

- (void)interrupt;

@end
NS_ASSUME_NONNULL_END