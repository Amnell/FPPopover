//
//  FPPopoverController.h
//
//  Created by Alvise Susmel on 1/5/12.
//  Copyright (c) 2012 Fifty Pixels Ltd. All rights reserved.
//
//  https://github.com/50pixels/FPPopover

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#import "FPPopoverView.h"
#import "FPTouchView.h"

@class FPPopoverController;
@protocol FPPopoverControllerDelegate <NSObject>

@optional
- (void)popoverControllerDidDismissPopover:(FPPopoverController *)popoverController;
- (void)presentedNewPopoverController:(FPPopoverController *)newPopoverController 
          shouldDismissVisiblePopover:(FPPopoverController*)visiblePopoverController;
@end

@interface FPPopoverController : UIViewController
{
    FPTouchView *_touchView;
    FPPopoverView *_contentView;
    UIViewController *_viewController;
    UIWindow *_window;
    UIView *_fromView;
    UIDeviceOrientation _deviceOrientation;
}
@property(nonatomic, unsafe_unretained) id<FPPopoverControllerDelegate> delegate;
/** @brief FPPopoverArrowDirectionAny, FPPopoverArrowDirectionVertical or FPPopoverArrowDirectionHorizontal for automatic arrow direction.
 **/
@property(nonatomic) FPPopoverArrowDirection arrowDirection;

@property(nonatomic) CGSize contentSize;
@property(nonatomic) CGPoint origin;

/** @brief The tint of the popover. **/
@property(nonatomic) FPPopoverTint tint;

/** @brief The border style of the content view in popover. **/
@property(nonatomic) FPPopoverContentBorder contentBorder;

/** @brief Initialize the popover with the content view controller
 **/
-(id)initWithViewController:(UIViewController*)viewController;

/** @brief Presenting the popover from a specified view **/
-(void)presentPopoverFromView:(UIView*)fromView;

/** @brief Presenting the popover from a specified point **/
-(void)presentPopoverFromPoint:(CGPoint)fromPoint;


/** @brief Dismiss the popover **/
-(void)dismissPopoverAnimated:(BOOL)animated;





@end
