# -*- coding: utf-8 -*-
#---------------------------------------
#   程序：百度贴吧爬虫
#   版本：0.2
#   作者：Andrew
#   日期：2014-11-28
#   语言：Python 2.7
#   操作：输入网址后自动只看楼主并保存到本地文件
#   功能：将楼主发布的页面下载并存储到本地文件夹。
#---------------------------------------
 
import string
import urllib2
import re

class Baidu_Spider:
    def __init__(self,url):  
        self.myUrl = url + '?see_lz=1'
        self.datas = []
  
    # 初始化加载页面并将其转码储存
    def baidu_tieba(self):
        # 读取页面的原始信息
        myPage = urllib2.urlopen(self.myUrl).read()
        
        # 百度贴吧的编码是 gbk 编码，将其转换成 unicode 编码
        #uPage = myPage.decode("gbk")

        # 计算楼主发布内容一共有多少页
        endPage = self.page_counter(myPage)

        # 获取最终的数据
        self.save_data(self.myUrl,endPage)

    #用来计算一共有多少页
    def page_counter(self,myPage):
        # 匹配 "共有<span class="red">12</span>页" 来获取一共有多少页
        myMatch = re.search(r'class="red">(\d\d)</span>', myPage, re.S)
        if myMatch:  
            endPage = int(myMatch.group(1))
            print u'楼主一共发布了%d页的内容' % endPage
        else:
            endPage = 1
            print u'无法计算楼主发布内容有多少页！'
        return endPage

    # 用来存储楼主发布的内容
    def save_data(self,url,endPage):
        url = url + '&pn='
        for i in range(1,endPage+1):
            sName = string.zfill(i,5) + '.html'#自动填充成六位的文件名
            print u'正在下载第' + str(i) + u'个网页，并将其存储为' + sName + '......'
            f = open(sName,'w+')
            m = urllib2.urlopen(url + str(i)).read()
            f.write(m)
            f.close()
 
#-------- 在这里输入参数 ------------------
print u"""#---------------------------------------
#   程序：百度贴吧爬虫
#   版本：0.2
#   作者：Andrew
#   日期：2014-11-28
#   语言：Python 2.7
#   操作：输入网址后自动只看楼主并保存到本地文件
#   功能：下载楼主的所有发帖并存储为txt。
#---------------------------------------
"""

# 以某小说贴吧为例子
# bdurl = 'http://tieba.baidu.com/p/2296712428?see_lz=1&pn=1'

print u'例如：http://tieba.baidu.com/p/2296712428'
print u'请输入贴吧的地址：'
bdurl = str(raw_input(u' ')) 

#-------- 在这里输入参数 ------------------
 

#调用
mySpider = Baidu_Spider(bdurl)
mySpider.baidu_tieba()
