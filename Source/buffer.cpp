/*
  ==============================================================================

    buffer.cpp
    Created: 30 Mar 2022 10:23:59am
    Author:  Imaan Choudhury

  ==============================================================================
*/

#include "buffer.h"

void processBuffer(AudioBuffer<float> *buffer, float thresh){
    
    int numberOfChannels = buffer->getNumChannels();
    int numberOfSamples = buffer->getNumSamples();
   
    
    for (int c=0; c<numberOfChannels; c++)
    {
        const float* input = buffer->getReadPointer(c);
        float* output = buffer->getWritePointer(c);
        for (int n=0; n<numberOfSamples; n++)
        {
            // Example of the functions
            if (input[n] >= thresh) {
                output[n] = thresh;
            } else if (input[n] >= -thresh) {
                output[n] = -thresh;
            } else {
                output[n] = input[n];
            }
        }
    }
}
