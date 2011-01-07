//
//  WiDrive_SocketAppDelegate.m
//  WiDrive-Socket
//
//  Created by Gavin Williams on 01/03/2010.
//  Copyright Apple Inc 2010. All rights reserved.
//

#import "WiDrive_SocketAppDelegate.h"
#import "WiDrive_SocketViewController.h"

@implementation WiDrive_SocketAppDelegate

@synthesize window;
@synthesize viewController;


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
    
    // Override point for customization after app launch    
    [window addSubview:viewController.view];
    [window makeKeyAndVisible];
	
	return YES;
}


- (void)dealloc {
    [viewController release];
    [window release];
    [super dealloc];
}


@end
