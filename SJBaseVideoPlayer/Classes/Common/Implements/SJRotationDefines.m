
#import "SJRotationDefines.h"

NSNotificationName const SJRotationManagerRotationNotification = @"SJRotationManagerRotationNotification";
NSNotificationName const SJRotationManagerTransitionNotification = @"SJRotationManagerTransitionNotification";

BOOL
SJRotationIsFullscreenOrientation(SJOrientation orientation) {
    switch (orientation) {
        case SJOrientation_Portrait:
            return NO;
        case SJOrientation_LandscapeLeft:
        case SJOrientation_LandscapeRight:
            return YES;
    }
    return NO;
}

BOOL
SJRotationIsSupportedOrientation(SJOrientation orientation, SJOrientationMask supportedOrientations) {
    return supportedOrientations & (1 << orientation);
}