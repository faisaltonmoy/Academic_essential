clc;
clear all;

Img = imread('input1.jpg');
Img = rgb2gray(Img);
Img = imnoise(Img,'Gaussian',0.05,0.005);
[row,col] = size(Img);

kernelSize = 5;
prompt = 'Enter the sigma value = ';
sigma = input(prompt);
 
gausian_X = zeros(kernelSize,kernelSize);
gausian_Y = zeros(kernelSize,kernelSize);

start = -2;
for i = 1:kernelSize
    gausian_X(1:kernelSize, i:i) = start;
    start = start + 1 ;
end
start = -2;
for i = 1:kernelSize
    gausian_Y(i:i, 1:kernelSize) = start;
    start = start + 1 ;
end

gausian_X
gausian_Y


%gaussian filtering equation 
g_X_Y = -(power(gausian_X,2) + power(gausian_Y,2)) / (2*power(sigma,2));
g_X_Y = exp(g_X_Y);
g_X_Y = (1.0 / (2 * pi * power(sigma,2))) * g_X_Y

nImg = zeros(row+2,col+2);
%bordering with 0s
nImg(2:row+1,2:col+1) = Img(1:row,1:col);

[nRow,nCol] = size(nImg);

outputImage = zeros(row,col);

for i = 1:nRow - (kernelSize-1)
    for j = 1:nCol- (kernelSize-1)
       nImg(i:i + (kernelSize-1) ,j:j +(kernelSize-1));
       data =  nImg(i:i + (kernelSize-1) ,j:j + (kernelSize-1)).*g_X_Y ;
       data = sum( data(:) );
       outputImage(i,j) = data;
    end
end


outputImage = uint8(outputImage);

subplot(2,1,1),imshow(Img),title("Input Image");
subplot(2,1,2),imshow(outputImage),title(strcat("Output Image (with a sigma value of ",num2str(sigma),")"));
imwrite(outputImage,'output.jpg')