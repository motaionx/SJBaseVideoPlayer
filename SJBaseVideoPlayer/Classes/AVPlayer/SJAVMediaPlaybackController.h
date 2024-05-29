
#import "SJMediaPlaybackController.h"
#import "SJAVMediaPlayer.h"
#import "SJAVMediaPlayerLayerView.h"

NS_ASSUME_NONNULL_BEGIN
@interface SJAVMediaPlaybackController : SJMediaPlaybackController

@property (nonatomic, strong, readonly, nullable) SJAVMediaPlayer *currentPlayer;
@property (nonatomic, strong, readonly, nullable) SJAVMediaPlayerLayerView *currentPlayerView;
@property (nonatomic) BOOL accurateSeeking;

@end

@interface SJAVMediaPlaybackController (SJAVMediaPlaybackAdd)<SJMediaPlaybackExportController, SJMediaPlaybackScreenshotController>

@end
NS_ASSUME_NONNULL_END