//
//  WiDrive_SocketAppDelegate.h
//  WiDrive-Socket
//
//  Created by Gavin Williams on 01/03/2010.
//  Copyright Apple Inc 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class WiDrive_SocketViewController;

@interface WiDrive_SocketAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    WiDrive_SocketViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet WiDrive_SocketViewController *viewController;

@end

