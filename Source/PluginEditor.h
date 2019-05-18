/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class EthanA3AudioProcessorEditor  : public AudioProcessorEditor, Slider::Listener
{
public:
    EthanA3AudioProcessorEditor (EthanA3AudioProcessor&);
    ~EthanA3AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void sliderValueChanged(Slider* slider) override
	{
		if (slider == &mixSlider)
		{
			processor.mixLevel = mixSlider.getValue();
		}
		else if (slider == &BitCrushSlider)
		{
			processor.bit = BitCrushSlider.getValue();
		}

	}

private:
  

	juce::Image backGround;

	Slider mixSlider;
	Label mixLabel;


	Slider BitCrushSlider;
	Slider BitCrushLabel;

    EthanA3AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EthanA3AudioProcessorEditor)
};
