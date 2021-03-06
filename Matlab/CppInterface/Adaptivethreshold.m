function BinaryImage = Adaptivethreshold(IM, ws, C, tm)
%ADAPTIVETHRESHOLD An adaptive thresholding algorithm that seperates the
%foreground from the background with nonuniform illumination.
%  bw=adaptivethreshold(IM,ws,C) outputs a binary image bw with the local 
%   threshold mean-C or median-C to the image IM.
%  ws is the local window size.
%  tm is 0 or 1, a switch between mean and median. tm=0 mean(default); tm=1 median.
%
%  Contributed by Guanglei Xiong (xgl99@mails.tsinghua.edu.cn)
%  at Tsinghua University, Beijing, China.
%
%  For more information, please see
%  http://homepages.inf.ed.ac.uk/rbf/HIPR2/adpthrsh.htm

if tm==0
    mIM=imfilter(IM, fspecial('average',ws),'replicate');
else
    mIM=medfilt2(IM, [ws ws]);
end

sIM=mIM-IM-C;
BinaryImage=imcomplement(imbinarize(sIM, 0));

