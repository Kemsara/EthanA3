/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "JuceHeader.h"

//==============================================================================
EthanA3AudioProcessorEditor::EthanA3AudioProcessorEditor (EthanA3AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	setOpaque(true);
	setSize(600, 300);
}

EthanA3AudioProcessorEditor::~EthanA3AudioProcessorEditor()
{
}

//==============================================================================
void EthanA3AudioProcessorEditor::paint (Graphics& g)
{
	Image background = ImageCache::getFromMemory(BinaryData::Pink_background_png, BinaryData::Pink_background_pngSize);
	g.drawImageAt(background, 0, 0);
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello VST", getLocalBounds(), Justification::centred, 1);




	//============mix slider===============================================
	addAndMakeVisible(mixLabel);
	mixLabel.setText("Mix", dontSendNotification);
	mixLabel.attachToComponent(&mixSlider, true);
	mixSlider.addListener(this);
	mixSlider.setRange(0.00f, 1);
	addAndMakeVisible(mixSlider);
	mixSlider.setNumDecimalPlacesToDisplay(2);
	mixSlider.setTextValueSuffix(" %");
	


	//============BitCrush===================================================
	addAndMakeVisible(BitCrushSlider);
	BitCrushSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove,
		false, 120, BitCrushSlider.getTextBoxWidth());
	BitCrushSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	BitCrushSlider.setRange(0.00f, 32767);
	BitCrushSlider.addListener(this);
	BitCrushSlider.setNumDecimalPlacesToDisplay(0);
	BitCrushSlider.setSkewFactorFromMidPoint(500.0f);




	

}

void EthanA3AudioProcessorEditor::resized()
{

	

	


	mixSlider.setBounds(50, 100, 300, 300);


	BitCrushSlider.setBounds(400, 50, 70, 200);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
