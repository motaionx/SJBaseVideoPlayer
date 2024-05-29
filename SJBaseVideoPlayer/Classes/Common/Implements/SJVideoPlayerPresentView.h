
#import <UIKit/UIKit.h>
#import "SJVideoPlayerPresentViewDefines.h"
#import "SJGestureControllerDefines.h"
@protocol SJVideoPlayerPresentViewDelegate;

NS_ASSUME_NONNULL_BEGIN
@interface SJVideoPlayerPresentView : UIView<SJVideoPlayerPresentView, SJGestureController>
@property (nonatomic, weak, nullable) id<SJVideoPlayerPresentViewDelegate> delegate;
@end

@protocol SJVideoPlayerPresentViewDelegate <NSObject>
@optional
- (void)presentViewDidLayoutSubviews:(SJVideoPlayerPresentView *)presentView;
- (void)presentViewDidMoveToWindow:(SJVideoPlayerPresentView *)presentView;
@end
NS_ASSUME_NONNULL_END