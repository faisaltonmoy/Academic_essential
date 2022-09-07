clc; 
clear all;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 1  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ia = imread('Image1.jpg');
Ia = im2double(Ia);

subplot(2,4,1); imshow(Ia); title('Figure (a)');


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 2  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
I2 = zeros(size(Ia) + 2);
[x,y] = size(I2);
I2(2:x-1,2:y-1) = Ia;

laplacian= [0  1  0; 
            1 -4  1; 
            0  1  0];

Ib = zeros(size(I2));

for i = 2:x-1
    for j =2:y-1
        Temp = I2(i-1:i+1,j-1:j+1).*laplacian;
        Ib(i,j)=sum(Temp(:));
    end
end

subplot(2,4,2); imshow(Ib,[]); title('Figure (b)');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 3  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ic = Ia - Ib(2:x-1, 2:y-1);
subplot(2,4,3); imshow(Ic); title('Figure (c)');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 4  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
sx = [-1  0  1; 
      -2  0  2; 
      -1  0  1];
  
sy = [-1 -2 -1; 
       0  0  0; 
       1  2  1];
  
threshold = 0.1;

p1 = zeros(size(I2));
p2 = zeros(size(I2));

for i = 2:x-1
    for j =2:y-1
        Temp2 = I2(i-1:i+1,j-1:j+1).*sx;
        p1(i,j)=sum(Temp2(:));
    end
end

for i = 2:x-1
    for j =2:y-1
        Temp3 = I2(i-1:i+1,j-1:j+1).*sy;
        p2(i,j)=sum(Temp3(:));
    end
end

Id = sqrt(p1.^2 + p2.^2);
for i = 1:x
    for j =1:y
        if(Id(i,j)<threshold)
            Id(i,j)=0;
        end
    end
end

subplot(2,4,4); imshow(Id(2:x-1,2:y-1)); title('Figure (d)');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 5  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
avgfilter = [1/25 1/25 1/25 1/25 1/25; 
      1/25 1/25 1/25 1/25 1/25;
      1/25 1/25 1/25 1/25 1/25; 
      1/25 1/25 1/25 1/25 1/25;
      1/25 1/25 1/25 1/25 1/25];

O2=zeros(size(Id)+2);
[x,y]=size(O2);
O2(2:x-1,2:y-1) = Id;

avg_img = zeros(size(O2));
  
for i = 3:x-2
    for j =3:y-2
        Temp4 = O2(i-2:i+2,j-2:j+2).*avgfilter;
        avg_img(i,j)=sum(Temp4(:));
    end
end

Ie = avg_img(3:x-2,3:y-2);
subplot(2,4,5); imshow(Ie); title('Figure (e)');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 6  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
If = Ic.*Ie;
subplot(2,4,6); imshow(If); title('Figure (f)');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 7  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ig = Ia+If;
subplot(2,4,7); imshow(Ig); title('Figure (g)');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Step 8  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
c = 1;
gamma = 0.5;

[x,y] = size(Ig);
Ih = zeros(size(Ig));
for i = 1:x
    for j =1:y
        Ih(i,j) = c.*(Ig(i,j).^gamma);
    end
end

subplot(2,4,8); imshow(Ih); title('Figure (h)');
