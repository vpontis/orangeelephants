#ifndef _CREATEVISION_H_
#define _CREATEVISION_H_

int visionAvgX(int ch, int confidence);
int getTotalConfidence(int ch);
int getBlobArea(int ch, int i);
int getLargestBlob(int ch);
int getLargestArea(int ch);

#endif
