
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

@interface SJBaseVideoPlayerResourceLoader : NSObject

+ (UIImage * __nullable)imageNamed:(NSString *)name;

@end

NS_ASSUME_NONNULL_END