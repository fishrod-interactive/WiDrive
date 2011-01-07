//
//  Car.m
//  WiDrive-Socket
//
//  Created by Gavin Williams on 13/04/2010.
//  Copyright 2010 fishrod interactive. All rights reserved.
//

#import "Car.h"

@implementation Car

@synthesize speed, heading, address;

-(id) init: (NSString *)carAddress carDelegate: (id)carDelegate {
	
	address = carAddress;
	socket = [[AsyncSocket alloc] initWithDelegate:self];

	speed = (NSInteger *) 90;
	heading = (NSInteger *) 90;
	delegate = carDelegate;
	
	[NSTimer scheduledTimerWithTimeInterval:0.05 target:self selector:@selector(timerSendCommand:) userInfo:nil repeats:YES];
	
	return self;
}

-(void) send {
	if ([socket isConnected]) {
		NSData *command = [[NSString stringWithFormat:@"%03d%03d\n", speed, heading] dataUsingEncoding:NSASCIIStringEncoding];
		[socket writeData:command withTimeout:-1 tag:0];
	}
}

-(void) disconnect {
	[self neutral];
	[self send];
	[socket disconnectAfterWriting];
}

-(void) connect {
	
	@try {
		NSError *err;
		if ([socket connectToHost:address onPort:1000 error:&err]) {
			NSLog (@"Connecting to %@ port %u.", address, 1000);
		} else {
			NSLog (@"Couldn't connect to %@ port %u (%@).", address, 1000, err);
		}
		
	}
	@catch (NSException * e) {
		NSLog(@"%@", [e reason]);
	} 
	
}

-(void)timerSendCommand:(NSTimer *)timer {
	[self send];
}

// AsyncSocket delegates
-(void) onSocket:(AsyncSocket *)sock didConnectToHost:(NSString *)host port:(UInt16)port {
	// Start sending the current command over the socket connection
	NSLog (@"Connected to %@ port %u.", host, 1000);
	if([delegate respondsToSelector:@selector(onCarConnect:)]){
		[delegate onCarConnect:self];
	}
}

-(void)onSocketDidDisconnect:(AsyncSocket *)sock {
	NSLog(@"Disconnected");
	if([delegate respondsToSelector:@selector(onCarDisconnect:)]){
		[delegate onCarDisconnect:self];
	}
}

-(void) neutral {
	speed = (NSInteger *) 90;
	heading = (NSInteger *) 90;
}

-(void) dealloc {
	[socket release];
	[super dealloc];
}

@end
