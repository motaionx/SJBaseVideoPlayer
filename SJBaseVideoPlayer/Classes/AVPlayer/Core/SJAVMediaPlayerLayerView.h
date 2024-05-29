
#import <UIKit/UIKit.h>
#import "SJMediaPlaybackController.h"

NS_ASSUME_NONNULL_BEGIN

@interface SJAVMediaPlayerLayerView : UIView<SJMediaPlayerView>
@property (nonatomic, strong, readonly) AVPlayerLayer *layer;
- (void)setScreenshot:(nullable UIImage *)image;
@end

NS_ASSUME_NONNULL_END