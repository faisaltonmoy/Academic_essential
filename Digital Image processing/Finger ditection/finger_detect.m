clc;
clear;
close all;

for i = 0:4
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Reading Images
    if (i == 0)
        Output1 = imread('f1.png');
    elseif (i == 1)
        Output1 = imread('f2.png');
    elseif (i == 2)
        Output1 = imread('f3.png');
    elseif (i == 3)
        Output1 = imread('f4.png');
    elseif (i == 4)
        Output1 = imread('f5.png');
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Coverting to Binary Image
    Output2 = im2bw(rgb2gray(Output1), 0);
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Extracting Palm (first erosion, then dialation)
    StructElement = strel('disk',60);   
    Erosion = imerode(Output2, StructElement);  
    Dilation = imdilate(Erosion, StructElement);  
    Output3 = Dilation;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Extracting Fingers (Noisy)
    Output4 = Output2 - Output3;
      
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Extracting Fingers (Noiseless)
    StructElement = strel('disk',10);
    Erosion = imerode(Output4, StructElement);
    Output5 = Erosion;
   
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Number of fingers
    [img,Output6] = bwlabel(Output5);

    subplot(5, 6, i*6+1); imshow(Output1); title('Original');
    
    subplot(5, 6, i*6+2); imshow(Output2); title('Binary Image');
    
    subplot(5, 6, i*6+3); imshow(Output3); title('Palm');
    
    subplot(5, 6, i*6+4); imshow(Output4); title('Fingers (Noisy)');

    subplot(5, 6, i*6+5); imshow(Output5); title('Fingers(NoiseleSS)');

    subplot(5, 6, i*6+6); text(0.5, 0.5, int2str(Output6)); title('Number of Finger'); xticks([]); yticks([]);   
end