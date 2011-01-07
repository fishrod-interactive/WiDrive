//
//  WiDrive_SocketViewController.h
//  WiDrive-Socket
//
//  Created by Gavin Williams on 01/03/2010.
//  Copyright Apple Inc 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreLocation/CoreLocation.h>
#import "Car.h"


#define degreesToRadians(x) (M_PI * (x) / 180.0)
#define kFilteringFactor 0.05 // The higher this number the more sensitive and juddery the accelerometer is
UIAccelerationValue accelerationY;
UIAccelerationValue accelerationX;

@interface WiDrive_SocketViewController : UIViewController <UIAccelerometerDelegate, CLLocationManagerDelegate> {
	
	UIAccelerometer *accelerometer;
	
	IBOutlet UIImageView* steeringWheel;
	IBOutlet UISlider *speedSlider;
	
	IBOutlet UIButton *btnStart;
	IBOutlet UIButton *btnStop;
	
	IBOutlet UIImageView *flags;
	IBOutlet UIImageView *dial;
	
	UISlider* forwardSlider;
	UISlider* reverseSlider;	
	CLLocationManager *locationManager;
	
	IBOutlet UIImageView *handbrakeIcon;
	IBOutlet UIImageView *indicatorLeftIcon;
	IBOutlet UIImageView *indicatorRightIcon;
	
	float startHeading;
	
	Car *car;	
}

@property (nonatomic, retain) UIAccelerometer *accelerometer;
@property (nonatomic, retain) UISlider *speedSlider;
@property (nonatomic, retain) UIButton *btnStart;
@property (nonatomic, retain) UIButton *btnStop;
@property (nonatomic, retain) UIImageView *flags;
@property (nonatomic, retain) UIImageView *dial;
@property (nonatomic, retain) UISlider *reverseSlider;
@property (nonatomic, retain) UIImageView *handbrakeIcon;
@property (nonatomic, retain) UIImageView *indicatorLeftIcon;
@property (nonatomic, retain) UIImageView *indicatorRightIcon;


-(IBAction)changeSpeed:(id)sender;
-(IBAction)start:(id)sender;
-(IBAction)stop:(id)sender;

-(void)rotateWheel:(int)degrees;

-(void)setSpeed:(int)speed;

-(void)onCarConnect:(Car *)carobj;
-(void)onCarDisconnect:(Car *)carobj;

@end