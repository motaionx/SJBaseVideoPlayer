
#import "NSString+SJBaseVideoPlayerExtended.h"

NS_ASSUME_NONNULL_BEGIN
@implementation NSString (SJBaseVideoPlayerExtended)

+ (instancetype)stringWithCurrentTime:(NSTimeInterval)currentTime duration:(NSTimeInterval)duration {
    long min = 60;
    long hour = 60 * min;
    
    long hours, seconds, minutes;
    hours = currentTime / hour;
    minutes = (currentTime - hours * hour) / 60;
    seconds = (NSInteger)currentTime % 60;
    if ( duration < hour ) {
        return [NSString stringWithFormat:@"%02ld:%02ld", minutes, seconds];
    }
    else if ( hours < 100 ) {
        return [NSString stringWithFormat:@"%02ld:%02ld:%02ld", hours, minutes, seconds];
    }
    else {
        return [NSString stringWithFormat:@"%ld:%02ld:%02ld", hours, minutes, seconds];
    }
}
@end
NS_ASSUME_NONNULL_END