
#ifndef SJControlLayerAppearManagerProtocol_h
#define SJControlLayerAppearManagerProtocol_h
#import <UIKit/UIKit.h>
@protocol SJControlLayerAppearManagerObserver;

NS_ASSUME_NONNULL_BEGIN
@protocol SJControlLayerAppearManager
- (id<SJControlLayerAppearManagerObserver>)getObserver;
@property (nonatomic, getter=isDisabled) BOOL disabled;         ///< 是否禁用显示管理类
@property (nonatomic) NSTimeInterval interval;                  ///< 控制层隐藏间隔, 默认5s

@property (nonatomic, readonly) BOOL isAppeared;
- (void)switchAppearState;
- (void)needAppear;
- (void)needDisappear;

- (void)resume;
- (void)keepAppearState;
- (void)keepDisappearState;

@property (nonatomic, copy, nullable) BOOL(^canAutomaticallyDisappear)(id<SJControlLayerAppearManager> mgr);
@end

@protocol SJControlLayerAppearManagerObserver
@property (nonatomic, copy, nullable) void(^onAppearChanged)(id<SJControlLayerAppearManager> mgr);
@end
NS_ASSUME_NONNULL_END
#endif /* SJControlLayerAppearManagerProtocol_h */