//
//  Car.h
//  WiDrive-Socket
//
//  Created by Gavin Williams on 13/04/2010.
//  Copyright 2010 fishrod interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CFStream.h>
#import "AsyncSocket.h"

@interface Car : NSObject {
	NSInteger *speed;
	NSInteger *heading;
	NSString *address;
	AsyncSocket *socket;
	id delegate;
}

@property NSInteger *speed;
@property NSInteger *heading;
@property (retain) NSString * address;

-(void)connect;
-(void)disconnect;
-(void)neutral;
-(void)send;
-(id)init:(NSString *)carAddress carDelegate:(id)carDelegate;

-(void)timerSendCommand:(NSTimer *)timer;

@end