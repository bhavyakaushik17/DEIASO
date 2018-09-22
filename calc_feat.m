function [feature] = calc_feat(LL, AA, FF, AiHn, mask,sortvals)

sum1=0;
count1=0;
j=0;
sum2=0;

mean_An = sum(AiHn, 2)/size(AiHn,2); % sum over i(time) for freq(n)

mean_Ai = sum(AiHn, 1)/size(AiHn,1); % sum over freq(n) for a time 

meanA = sum(mean_An)/size(mean_An, 1); % sum of all values of AiHn
mean_L = sum(LL)/size(LL, 1); %mean of all values of LL
feature(1) = sum(FF(2:4).*AA(2:4))/sum(AA(2:4));
feature(2) = FF(2);
feature(3) = FF(7);
feature(4) = FF(2)/FF(1);
feature(5) = AA(1)/AA(2);
% feature 6
suma=0;
for p= 1:4
    for q= 1: size(AiHn,2)
        suma=suma+abs(AiHn(p,q)-mean_An(p));
    end
end
sumb=0;
for p= 1:4
    for q= 1: size(AiHn,2);
        sumb=sumb+AiHn(p,q);
    end
end
feature(6) =suma/sumb;
%feature 7
feature(7) = sum(LL);
feature(8) = LL(2)+ LL(4);

%feature 9
for i= 1:8
feature(9) = feature(9) + (LL(i)-mean_L)*(LL(i)-mean_L);
end

%feature 10
for q= 1: size(AiHn,2)
        feature(10)=abs(AiHn(2,q)-mean_An(2));
end

feature(10) = feature(10)/mean_An(2);

%feature 11
D = sum(AiHn,1)/size(AiHn,1) - (sum(AiHn(:))/numel(AiHn));
for j= 1:size(AiHn,1)
E(j) = D(j+1)-D(j);
end
t1=E(1:size(E,2)-1);
t2=E(2:size(E,2));
tt=t1.*t2;
indx = find(tt<0);
feature(11) = size(indx,2);

%feature 12
t1=D(1:size(D,2)-1);
t2=D(2:size(D,2));
tt=t1.*t2;
indx = find(tt<0);
feature(12) = indx;

% feature 13
norm_AiHn = sum(sum(AiHn - meanA))/(80*meanA);
norm_AiHn = log2(norm_AiHn);
feature(13) = floor(norm_AiHn); %integer part of the normalized AiHn

% feature 14
sum_denom14 = sum(AiHn(1:4, :));
feature(14) = 80 * meanA / sum_denom14;

<<<<<<< HEAD
% feature 15
    
=======
temp=sum(mask,1);
temp=temp*0.5;
for i=1:642
{
sum1=0;
count1=0;
j=0;
while(sum1>temp(i))
{
sum1=sum1+sortvals(i,j);
j++;
count1++;
}end
sum2=sum2+count1;
}end

>>>>>>> 641a1b2f85660d567c0740d5cd3f1256492884de
feature(15)
feature(16)