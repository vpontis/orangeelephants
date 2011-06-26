/**
** \file createVision.c
** \brief Functions to utilize camera.
**
*/

#include "createVision.h"


/** \brief Determines the middle X-coordinate for the largest blob.
	
	Determines largest blob by calculated area. Also will measure 
	utilizes custom confidence measure before conducting calculations.
	\param ch Color channel to use.
*/
int visionAvgX(int ch){
	track_update();
	while(getTotalConfidence(ch) < MIN_CONFIDENCE){
		track_update();
		printf("Low Confidence. Reupdating... \n");
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
	
	return track_bbox_left(ch, largestBlob)+ 0.5*track_bbox_width(ch, largestBlob) - 0.5*X_MAX;
}


/** \brief Calculates confidence levels of blob tracking
	
	Uses the track_count, largest area of blob, and track_confidences 
	of each blob to determine total confidence of tracking. Assumes
	that track_update() has already been called. 
	\param ch Color channel to use.
*/
int getTotalConfidence(int ch){
	if(track_count(ch) == 0 || getLargestArea(ch) < MIN_BLOB_AREA){
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


/** \brief Calculates the area of a specified blob
	\param ch Color channel to use.
	\param i Blob number
*/
int getBlobArea(int ch, int i){
	return track_bbox_height(ch, i) * track_bbox_width(ch, i);
}


/** \brief Finds the blob number of largest blob
	\param ch Color channel to use.
*/
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


/** \brief Finds the area of largest blob
	\param ch Color channel to use.
*/
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
