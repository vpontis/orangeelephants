#include "createVision.h"
#include "boolean.h"

boolean CANT_SEE = false; 

int visionAvgX(int ch, int confidence){
	int initTime = seconds(); 
	track_update();
	while(getTotalConfidence(ch) < confidence){
		track_update();
		printf("Low Confidence. Reupdating... \n");
		if ((seconds()-initTime)>3) {
			beep(); 
			CANT_SEE = 1; 
			return 0; 
		}
	}
	int largestBlob = getLargestBlob(ch);
	int largestArea = getLargestArea(ch);
	printf("Largest Area is %d \n", largestArea);
	printf("Target is %d \n", track_bbox_left(ch, largestBlob)+ 0.5*track_bbox_width(ch, largestBlob) - 0.5*X_MAX);
	/*
	int i = 0;
	double sumX = 0;
	while(i < track_count(ch)){
		sumX = sumX + (getBlobArea(ch, i)/largestArea)*(track_x(ch, i) - 0.5*X_MAX);
		i++;
	}
	
	return (int) (sumX/track_count(ch));*/
	CANT_SEE = false; 
	return track_bbox_left(ch, largestBlob)+ 0.5*track_bbox_width(ch, largestBlob) - 0.5*X_MAX;
}

//assume track_update() has already been called.
int getTotalConfidence(int ch){
	if(track_count(ch) == 0 || getLargestArea(ch) < 1500){
		return 0;
	}
	
	int i = 0;
	int confidenceSum = 0;
	while(i < track_count(ch)){
		confidenceSum = confidenceSum + track_confidence(ch, i);
		i++;
	}
	
	return (int) (confidenceSum/track_count(ch));
}

int getBlobArea(int ch, int i){
	return track_bbox_height(ch, i) * track_bbox_width(ch, i);
}

int getLargestBlob(int ch){
	int i = 0;
	int largestArea = 0;
	int largestBlob = -1;
	while(i < track_count(ch)){
		if(getBlobArea(ch, i) > largestArea){
			largestArea = getBlobArea(ch, i);
			largestBlob = i;
		}
		i++;
	}
	return largestBlob;
}

int getLargestArea(int ch){
	int i = 0;
	int largestArea = 0;
	while(i < track_count(ch)){
		if(getBlobArea(ch, i) > largestArea){
			largestArea = getBlobArea(ch, i);
		}
		i++;
	}
	return largestArea;
}
