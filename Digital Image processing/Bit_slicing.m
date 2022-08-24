clc;
clear all;
figure
%a. Take a RGB input image and convert it into grayscale image.
II = imread('input1.jpg');
C = 480;
I = imresize(II, [C C]);
subplot(2, 5, 1);
imshow(I); 
title('Main Image');
R = rgb2gray(I);
subplot(2, 5, 2);
imshow(R); 
title('Grayscale Image');

%b. Extract the dimension of the grayscale image (say R).
disp ("Grayscale Image Dimension:")
[row, col] = size(R);
disp ("Row:")
disp (row)
disp ("Column:")
disp (col)

J = double(R);
for i=1:8   %
    %c. For every column of bit depth of R, starting from the LSB, take the
    %   column number of the bit positions (say k) of R.
    k=i-1;
    
    %d. For every k, calculate X, where X is 2 to the power of that column number.
    X = 2^k;
    
    %e. Calculate the bitwise and operation for every pixel of the image using
    %   the following function.
    %   S= bitand(A,B)
    NewImage = bitand(J,X);
    
    %f. Show the output images (S) for every bit position.
    %   It is recommended to use subplot function for showing the output
    %   images.
    subplot(2,5,i+2);
    imshow(NewImage);
    title(strcat('Output for Bit:',num2str(i)));
end