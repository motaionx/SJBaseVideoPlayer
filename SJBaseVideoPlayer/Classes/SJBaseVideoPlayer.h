
#import <UIKit/UIKit.h>
#import "SJFitOnScreenManagerDefines.h"
#import "SJRotationManagerDefines.h"
#import "SJVideoPlayerControlLayerProtocol.h"
#import "SJControlLayerAppearManagerDefines.h"
#import "SJFlipTransitionManagerDefines.h"
#import "SJVideoPlayerPlaybackControllerDefines.h"
#import "SJVideoPlayerURLAsset+SJAVMediaPlaybackAdd.h"
#import "SJGestureControllerDefines.h"
#import "SJDeviceVolumeAndBrightnessControllerDefines.h"
#import "SJSmallViewFloatingControllerDefines.h"
#import "SJVideoDefinitionSwitchingInfo.h"
#import "SJPromptingPopupControllerDefines.h"
#import "SJPlaybackObservation.h"
#import "SJVideoPlayerPresentViewDefines.h"
#import "SJSubtitlePopupControllerDefines.h"
#import "SJDanmakuPopupControllerDefines.h"
#import "SJTextPopupControllerDefines.h"
#import "SJWatermarkViewDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface SJBaseVideoPlayer : NSObject
+ (NSString *)version;
+ (instancetype)player;
- (instancetype)init;

@property (nonatomic) SJVideoGravity videoGravity;

@property (nonatomic, strong, readonly) __kindof UIView *view;
@property (nonatomic, weak, nullable) id <SJVideoPlayerControlLayerDataSource> controlLayerDataSource;
@property (nonatomic, weak, nullable) id <SJVideoPlayerControlLayerDelegate> controlLayerDelegate;
@end


@interface SJBaseVideoPlayer (AudioSession)
@property (nonatomic, getter=isAudioSessionControlEnabled) BOOL audioSessionControlEnabled;

- (void)setCategory:(AVAudioSessionCategory)category withOptions:(AVAudioSessionCategoryOptions)options;
- (void)setActiveOptions:(AVAudioSessionSetActiveOptions)options;
@end


#pragma mark - present view

@interface SJBaseVideoPlayer (Placeholder)
@property (nonatomic, strong, readonly) UIView<SJVideoPlayerPresentView> *presentView;

@property (nonatomic) BOOL automaticallyHidesPlaceholderImageView;

@property (nonatomic) NSTimeInterval delayInSecondsForHiddenPlaceholderImageView;
@end

#pragma mark - 镜像翻转

@interface SJBaseVideoPlayer (VideoFlipTransition)

@property (nonatomic, strong, null_resettable) id<SJFlipTransitionManager> flipTransitionManager; ///< 镜像翻转

@property (nonatomic, strong, readonly) id<SJFlipTransitionManagerObserver> flipTransitionObserver;
@end



#pragma mark - 播放控制

@interface SJBaseVideoPlayer (Playback)<SJVideoPlayerPlaybackControllerDelegate>

@property (nonatomic, strong, null_resettable) __kindof id<SJVideoPlayerPlaybackController> playbackController;

@property (nonatomic, strong, readonly) SJPlaybackObservation *playbackObserver;

@property (nonatomic, strong, nullable) SJVideoPlayerURLAsset *URLAsset;

@property (nonatomic, readonly) SJAssetStatus assetStatus;

@property (nonatomic, readonly) SJPlaybackTimeControlStatus timeControlStatus;

@property (nonatomic, readonly, nullable) SJWaitingReason reasonForWaitingToPlay;


@property (nonatomic, readonly) BOOL isPaused;          ///< 调用了暂停, 暂停播放
@property (nonatomic, readonly) BOOL isPlaying;         ///< 调用了播放, 处于播放中
@property (nonatomic, readonly) BOOL isBuffering;       ///< 调用了播放, 处于缓冲中(等待缓存足够时自动恢复播放, 建议显示loading视图)
@property (nonatomic, readonly) BOOL isEvaluating;      ///< 调用了播放, 正在评估缓冲中(这个过程会进行的很快, 不需要显示loading视图)
@property (nonatomic, readonly) BOOL isNoAssetToPlay;   ///< 调用了播放, 但未设置播放资源(设置资源后将会自动播放 )

@property (nonatomic, readonly) BOOL isPlaybackFailed;                              ///< 播放失败
@property (nonatomic, readonly) BOOL isPlaybackFinished;                            ///< 播放结束
@property (nonatomic, readonly, nullable) SJFinishedReason finishedReason;          ///< 播放结束的reason

- (void)play;           ///< 使播放
- (void)pause;          ///< 使暂停, 方法`pauseForUser`与`pause`两者都能使播放器暂停, 它们主要用来`区分是用户还是开发者暂停的`
- (void)pauseForUser;   ///< 使暂停, 表示是用户暂停的. 可通过`player.isUserPaused`查看
- (void)refresh;        ///< 刷新当前资源, 将重新初始化当前的资源, 适合播放失败时调用
- (void)replay;         ///< 重播, 适合播放完毕后调用进行重播
- (void)stop;           ///< 使停止, 请注意: 当前资源将会被清空, 如需重播, 请重新设置新资源

@property (nonatomic, getter=isMuted) BOOL muted;                                   ///< 禁音
@property (nonatomic) float playerVolume;                                           ///< 设置播放声音
@property (nonatomic) float rate;                                                   ///< 设置播放速率

@property (nonatomic, readonly) NSTimeInterval currentTime;                         ///< 当前播放到的时间
@property (nonatomic, readonly) NSTimeInterval duration;                            ///< 总时长
@property (nonatomic, readonly) NSTimeInterval playableDuration;                    ///< 缓冲到的时间
@property (nonatomic, readonly) NSTimeInterval durationWatched;                     ///< 当前资源已观看的时长

@property (nonatomic, readonly) BOOL isUserPaused;                                  ///< 表示是否是用户暂停的
@property (nonatomic, readonly) BOOL isPlayed;                                      ///< 当前的资源是否调用过`play`
@property (nonatomic, readonly) BOOL isReplayed;                                    ///< 当前的资源是否调用过`replay`
@property (nonatomic, readonly) SJPlaybackType playbackType;                        ///< 播放类型
- (NSString *)stringForSeconds:(NSInteger)secs;                                     ///< 转换时间为字符串, format: 00:00:00

@property (nonatomic, getter=isPausedInBackground) BOOL pausedInBackground; ///< 进入后台是否暂停;
@property (nonatomic) BOOL autoplayWhenSetNewAsset;                    ///< 设置新的资源后, 是否自动调用播放. 默认为 YES
@property (nonatomic) BOOL resumePlaybackWhenAppDidEnterForeground;    ///< 进入前台时, 是否恢复播放. 默认为 NO
@property (nonatomic) BOOL resumePlaybackWhenPlayerHasFinishedSeeking; ///< 当`seekToTime:`操作完成后, 是否恢复播放. 默认为 YES

@property (nonatomic, copy, nullable) BOOL(^canPlayAnAsset)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic, copy, nullable) BOOL(^canSeekToTime)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic) BOOL accurateSeeking;

- (void)seekToTime:(NSTimeInterval)secs completionHandler:(void (^ __nullable)(BOOL finished))completionHandler;
- (void)seekToTime:(CMTime)time toleranceBefore:(CMTime)toleranceBefore toleranceAfter:(CMTime)toleranceAfter completionHandler:(void (^ __nullable)(BOOL finished))completionHandler;

- (void)switchVideoDefinition:(SJVideoPlayerURLAsset *)URLAsset;

@property (nonatomic, strong, readonly) SJVideoDefinitionSwitchingInfo *definitionSwitchingInfo;

@property (nonatomic, strong, readonly, nullable) NSError *error;
@end


#pragma mark - 设置 设备的音量和亮度

@interface SJBaseVideoPlayer (DeviceVolumeAndBrightness)

@property (nonatomic, strong, null_resettable) id<SJDeviceVolumeAndBrightnessController> deviceVolumeAndBrightnessController;

@property (nonatomic, strong, readonly) id<SJDeviceVolumeAndBrightnessControllerObserver> deviceVolumeAndBrightnessObserver;

@property (nonatomic) BOOL disableBrightnessSetting;

@property (nonatomic) BOOL disableVolumeSetting;
@end


#pragma mark - 关于视图控制器

@interface SJBaseVideoPlayer (Life)

- (void)vc_viewDidAppear; 
- (void)vc_viewWillDisappear;
- (void)vc_viewDidDisappear;
- (BOOL)vc_prefersStatusBarHidden;
- (UIStatusBarStyle)vc_preferredStatusBarStyle;


@property (nonatomic) BOOL vc_isDisappeared;


- (void)needShowStatusBar;

- (void)needHiddenStatusBar;
@end




#pragma mark - 网络状态

@interface SJBaseVideoPlayer (Network)

@property (nonatomic, strong, null_resettable) id<SJReachability> reachability;

@property (nonatomic, strong, readonly) id<SJReachabilityObserver> reachabilityObserver;
@end





#pragma mark - 弹出提示文本

@interface SJBaseVideoPlayer (Popup)

@property (nonatomic, strong, null_resettable) id<SJTextPopupController> textPopupController;

@property (nonatomic, strong, null_resettable) id<SJPromptingPopupController> promptingPopupController;
@end



#pragma mark - 手势控制相关操作
/**
 播放器的手势介绍:
 base video player 默认会存在 Single Tap, double Tap, Pan, Pinch, LongPress 这些手势.
 
 SingleTapGesture
 单击手势
 当用户单击播放器时, 播放器会调用显示或隐藏控制层的相关代理方法. 见 `controlLayerDelegate`
 
 DoubleTapGesture
 双击手势
 双击会触发暂停或播放的操作
 
 PanGesture
 移动手势
 当用户水平滑动时, 会触发控制层相应的代理方法. 见 `controlLayerDelegate`
 当用户垂直滑动时, 如果在屏幕左边, 则会触发调整亮度的操作, 并显示亮度提示视图. 如果在屏幕右边, 则会触发调整声音的操作, 并显示系统音量提示视图
 
 PinchGesture
 捏合手势
 当用户做放大或收缩触发该手势时, 会设置播放器显示模式`Aspect`或`AspectFill`.
 
 LongPressGesture
 长按手势
 当用户长按播放器时, 将加速播放. 该手势默认不会启用, 如需开启请设置`player.gestureController.supportedGestureTypes = SJPlayerGestureTypeMask_LongPress | 其他支持的手势;`
 */
@interface SJBaseVideoPlayer (Gesture)

@property (nonatomic, strong, readonly) id<SJGestureController> gestureController;

@property (nonatomic, copy, nullable) BOOL(^gestureRecognizerShouldTrigger)(__kindof SJBaseVideoPlayer *player, SJPlayerGestureType type, CGPoint location);

@property (nonatomic) BOOL allowHorizontalTriggeringOfPanGesturesInCells;

@property (nonatomic) CGFloat rateWhenLongPressGestureTriggered;

@property (nonatomic) CGFloat offsetFactorForHorizontalPanGesture;
@end





#pragma mark - 播放器控制层 显示/隐藏 控制

@interface SJBaseVideoPlayer (ControlLayer)
@property (nonatomic, strong, null_resettable) id<SJControlLayerAppearManager> controlLayerAppearManager;

@property (nonatomic, strong, readonly) id<SJControlLayerAppearManagerObserver> controlLayerAppearObserver;

@property (nonatomic, getter=isControlLayerAppeared) BOOL controlLayerAppeared;

@property (nonatomic, copy, nullable) BOOL(^canAutomaticallyDisappear)(__kindof SJBaseVideoPlayer *player);

/**
 显示控制层
 
 When you want to appear the control layer, you should call this method to appear.
 This method will call the control layer delegate method.
 
 - (void)controlLayerNeedAppear:(__kindof SJBaseVideoPlayer *)videoPlayer;
 */
- (void)controlLayerNeedAppear;

/**
 隐藏控制层
 
 When you want to disappear the control layer, you should call this method to disappear.
 This method will call the control layer delegate method.
 
 - (void)controlLayerNeedDisappear:(__kindof SJBaseVideoPlayer *)videoPlayer;
 */
- (void)controlLayerNeedDisappear;

@property (nonatomic) BOOL pausedToKeepAppearState;
@end


#pragma mark - 竖屏小屏 到 竖屏全屏

@interface SJBaseVideoPlayer (FitOnScreen)

@property (nonatomic, strong, null_resettable) id<SJFitOnScreenManager> fitOnScreenManager;

@property (nonatomic, strong, readonly) id<SJFitOnScreenManagerObserver> fitOnScreenObserver;

@property (nonatomic, getter=isFitOnScreen) BOOL fitOnScreen;

@property (nonatomic) BOOL onlyFitOnScreen;

- (void)setFitOnScreen:(BOOL)fitOnScreen animated:(BOOL)animated;

- (void)setFitOnScreen:(BOOL)fitOnScreen animated:(BOOL)animated completionHandler:(nullable void(^)(__kindof SJBaseVideoPlayer *player))completionHandler;
@end

#pragma mark - 竖屏小屏 旋转到 横屏全屏

@interface SJBaseVideoPlayer (Rotation)

@property (nonatomic, strong, nullable) id<SJRotationManager> rotationManager;

@property (nonatomic, strong, readonly) id<SJRotationManagerObserver> rotationObserver;

@property (nonatomic, copy, nullable) BOOL(^shouldTriggerRotation)(__kindof SJBaseVideoPlayer *player);

@property (nonatomic) BOOL allowsRotationInFitOnScreen;

/**
 Autorotation. Animated.
 */
- (void)rotate;

/**
 Rotate to the specified orientation.
 
 @param orientation     Any value of SJOrientation.
 @param animated        Pass YES to animate the rotation; otherwise, pass NO.
 */
- (void)rotate:(SJOrientation)orientation animated:(BOOL)animated;

/**
 Rotate to the specified orientation.
 
 @param orientation     Any value of SJOrientation.
 @param animated        Pass YES to animate the rotation; otherwise, pass NO.
 @param block           The block invoked when player rotated.
 */
- (void)rotate:(SJOrientation)orientation animated:(BOOL)animated completion:(void (^ _Nullable)(__kindof SJBaseVideoPlayer *player))block;

@property (nonatomic, readonly) BOOL isRotating;                                ///< 是否在旋转中
@property (nonatomic, readonly) BOOL isFullscreen;                              ///< 是否已全屏
@property (nonatomic, getter=isLockedScreen) BOOL lockedScreen;                 ///< 是否锁屏
@property (nonatomic, readonly) UIInterfaceOrientation currentOrientation;      ///< 当前的方向
@end





#pragma mark - 截图

@interface SJBaseVideoPlayer (Screenshot)


@property (nonatomic, copy, nullable) void(^presentationSizeDidChangeExeBlock)(__kindof SJBaseVideoPlayer *videoPlayer);

@property (nonatomic, readonly) CGSize videoPresentationSize;



- (UIImage * __nullable)screenshot;

- (void)screenshotWithTime:(NSTimeInterval)time
                completion:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, UIImage * __nullable image, NSError *__nullable error))block;

- (void)screenshotWithTime:(NSTimeInterval)time
                      size:(CGSize)size
                completion:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, UIImage * __nullable image, NSError *__nullable error))block;
@end





#pragma mark - 输出

@interface SJBaseVideoPlayer (Export)
- (void)exportWithBeginTime:(NSTimeInterval)beginTime
                   duration:(NSTimeInterval)duration
                 presetName:(nullable NSString *)presetName
                   progress:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, float progress))progressBlock
                 completion:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, NSURL *fileURL, UIImage *thumbnailImage))completion
                    failure:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, NSError *error))failure;

- (void)cancelExportOperation;

- (void)generateGIFWithBeginTime:(NSTimeInterval)beginTime
                        duration:(NSTimeInterval)duration
                        progress:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, float progress))progressBlock
                      completion:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, UIImage *imageGIF, UIImage *thumbnailImage, NSURL *filePath))completion
                         failure:(void(^)(__kindof SJBaseVideoPlayer *videoPlayer, NSError *error))failure;

- (void)cancelGenerateGIFOperation;

@end



#pragma mark - 在`tableView`或`collectionView`上播放

@interface SJBaseVideoPlayer (ScrollView)

- (void)refreshAppearStateForPlayerView;

@property (nonatomic, strong, null_resettable) id<SJSmallViewFloatingController> smallViewFloatingController;

@property (nonatomic, getter=isHiddenFloatSmallViewWhenPlaybackFinished) BOOL hiddenFloatSmallViewWhenPlaybackFinished;

@property (nonatomic) BOOL pausedWhenScrollDisappeared;

@property (nonatomic) BOOL resumePlaybackWhenScrollAppeared;

@property (nonatomic) BOOL hiddenViewWhenScrollDisappeared;

@property (nonatomic, readonly) BOOL isPlayOnScrollView;

@property (nonatomic, readonly) BOOL isScrollAppeared;

@property (nonatomic, copy, nullable) void(^playerViewWillAppearExeBlock)(__kindof SJBaseVideoPlayer *videoPlayer);
@property (nonatomic, copy, nullable) void(^playerViewWillDisappearExeBlock)(__kindof SJBaseVideoPlayer *videoPlayer);
@end


#pragma mark - 字幕

@interface SJBaseVideoPlayer (Subtitle)
@property (nonatomic, strong, null_resettable) id<SJSubtitlePopupController> subtitlePopupController;

@property (nonatomic) CGFloat subtitleBottomMargin;

@property (nonatomic) CGFloat subtitleHorizontalMinMargin;
@end


#pragma mark - 弹幕

@interface SJBaseVideoPlayer (Danmaku)

@property (nonatomic, strong, null_resettable) id<SJDanmakuPopupController> danmakuPopupController;
@end


#pragma mark - 水印视图

@interface SJBaseVideoPlayer (Watermark)

@property (nonatomic, strong, nullable) UIView<SJWatermarkView> *watermarkView;

- (void)updateWatermarkViewLayout;
@end


#pragma mark - 已弃用

@interface SJBaseVideoPlayer (Deprecated)
- (void)playWithURL:(NSURL *)URL; // 不再建议使用, 请使用`URLAsset`进行初始化
@property (nonatomic, strong, nullable) NSURL *assetURL;
@property (nonatomic, readonly) BOOL isPlayedToEndTime __deprecated_msg("use `isPlaybackFinished`;"); ///< 是否已播放结束(当前资源是否已播放结束)
@end
NS_ASSUME_NONNULL_END