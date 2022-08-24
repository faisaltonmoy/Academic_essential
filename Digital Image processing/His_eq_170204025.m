clc;
clear all;
%a. Read the image cameraman.png
I = imread('cameraman.png');
[row, col] = size(I);


%b. Compute no. of pixels for each gray level intensity (to generate histogram)
hist = zeros(1,256);
for i=1:row
    for j=1:col
        hist(I(i,j))= hist(I(i,j))+1;
    end
end

subplot(2,2,1);
imshow(I);
title('Main Image');
subplot(2,2,2);
bar(hist);
title('Histogram of Main Image');


%c. Compute Probability Distribution Function (PDF) = no. of pixels for each level 
%                                                        / total no of pixels
no_of_pix =zeros(1,256);
for i=1:row
    for j=1:col
        no_of_pix(I(i,j))= no_of_pix(I(i,j))+1;
    end
end

pdf = no_of_pix/sum(no_of_pix);


%d. Compute Cumulative Distribution Function (CDF) = Cumulative sum of PDF
cdf = zeros(1,256);
cdf(1) = pdf(1);
for i=2:256
    cdf(i)= pdf(i) + cdf(i-1);
end


%e. Multiplying the CDF by L-1
%f. Round the value obtained in step 5
max_I = max(max(I));
L = 2 ^ (floor(log2(double(max_I))) + 1);
new_cdf = zeros(1,256);
for i=1:256
    new_cdf(i)= round(cdf(i) * (L-1));
end


%g & h. Display original histogram and equalized histogram using subplot
new_I = I;
for i = 1:row
    for j = 1:col
        new_I(i,j) = new_cdf(new_I(i,j)+1);
    end
end

new_hist = zeros(1,256);
for i=1:row
    for j=1:col
        new_hist(new_I(i,j))= new_hist(new_I(i,j))+1;
    end
end

subplot(2,2,3);
imshow(new_I);
title('Equalized Image');
subplot(2,2,4);
bar(new_hist);
title('Histogram of Equalized Image');

%i. Perform Histogram Specification of the input image with your desired image 
%   (you can choose any of your image for performing the specification).
warning off;
A = imread('input1.jpg');
Ref = imread('peppers_color.jpg');
B = imhistmatch(A,Ref);
figure;
subplot(2,3,1);
imshow(A);
title('RGB Image');
subplot(2,3,2);
imshow(Ref);
title('Reference Color Image');
subplot(2,3,3);
imshow(B);
title('Histogram Specification Image');
subplot(2,3,4);
imhist(A);
title('Histogram of Problem Image');
subplot(2,3,5);
imhist(Ref);
title('Histogram of Reference Image');
subplot(2,3,6);
imhist(B);
title('Histogram of Enhanced Image');