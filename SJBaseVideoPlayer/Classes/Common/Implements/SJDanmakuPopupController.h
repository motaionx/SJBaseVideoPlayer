
#import "SJDanmakuPopupControllerDefines.h"
#import <UIKit/UIKit.h>
@protocol SJDanmakuTrackConfigurationDelegate;
@class SJDanmakuTrackConfiguration;

NS_ASSUME_NONNULL_BEGIN
@interface SJDanmakuPopupController : NSObject<SJDanmakuPopupController>
- (instancetype)initWithNumberOfTracks:(NSUInteger)numberOfTracks;

@property (nonatomic) NSInteger numberOfTracks;

@property (nonatomic, strong, readonly) SJDanmakuTrackConfiguration *trackConfiguration;

- (void)reloadTrackConfiguration; ///< 当配置修改后, 请调用该方法来刷新

@property (nonatomic, getter=isDisabled) BOOL disabled;

- (void)enqueue:(id<SJDanmakuItem>)item;
- (void)emptyQueue;
- (void)removeDisplayedItems;
- (void)removeAll;

@property (nonatomic, readonly, getter=isPaused) BOOL paused;
- (void)pause;
- (void)resume;

- (id<SJDanmakuPopupControllerObserver>)getObserver;

@property (nonatomic, strong, readonly) __kindof UIView *view;
@property (nonatomic, readonly) NSInteger queueSize; ///< 未显示的弹幕数量

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end


@interface SJDanmakuTrackConfiguration : NSObject

@property (nonatomic, weak, nullable) id<SJDanmakuTrackConfigurationDelegate> delegate;

@property (nonatomic) CGFloat rate;

@property (nonatomic) CGFloat itemSpacing;

@property (nonatomic) CGFloat topMargin;

@property (nonatomic) CGFloat height;
@end


@protocol SJDanmakuTrackConfigurationDelegate <NSObject>
@optional
- (CGFloat)trackConfiguration:(SJDanmakuTrackConfiguration *)trackConfiguration rateForTrackAtIndex:(NSInteger)index;
- (CGFloat)trackConfiguration:(SJDanmakuTrackConfiguration *)trackConfiguration itemSpacingForTrackAtIndex:(NSInteger)index;

- (CGFloat)trackConfiguration:(SJDanmakuTrackConfiguration *)trackConfiguration topMarginForTrackAtIndex:(NSInteger)index;
- (CGFloat)trackConfiguration:(SJDanmakuTrackConfiguration *)trackConfiguration heightForTrackAtIndex:(NSInteger)index;
@end
NS_ASSUME_NONNULL_END