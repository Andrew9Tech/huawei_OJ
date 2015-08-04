# -*- coding: utf-8 -*-
#---------------------------------------
#   程序：百度贴吧爬虫
#   版本：0.3
#   作者：andrew9tech
#   日期：2014-11-28
#   语言：Python 2.7
#   操作：输入网址后自动只看楼主并保存到本地文件
#   功能：将楼主发布的内容打包txt存储到本地。
#---------------------------------------
 
import string
import urllib2
import re

#----------- 处理页面上的各种标签 -----------
class HTML_Tool:
    # 用非 贪婪模式 匹配 \t 或者 \n 或者 空格 或者 超链接 或者 图片
    BgnCharToNoneRex = re.compile("(\t|\n| |<a.*?>|<img.*?>)")
    
    # 用非 贪婪模式 匹配 任意<>标签
    EndCharToNoneRex = re.compile("<.*?>")

    # 用非 贪婪模式 匹配 任意<p>标签
    BgnPartRex = re.compile("<p.*?>")
    CharToNewLineRex = re.compile("(<br/>|</p>|<tr>|<div>|</div>)")
    CharToNextTabRex = re.compile("<td>")

    # 将一些html的符号实体转变为原始符号
    replaceTab = [("&lt;","<"),("&gt;",">"),("&amp;","&"),("&amp;","\""),("&nbsp;"," ")]
    
    def Replace_Char(self,x):
        x = self.BgnCharToNoneRex.sub("",x)
        x = self.BgnPartRex.sub("\n    ",x)
        x = self.CharToNewLineRex.sub("\n",x)
        x = self.CharToNextTabRex.sub("\t",x)
        x = self.EndCharToNoneRex.sub("",x)

        for t in self.replaceTab:  
            x = x.replace(t[0],t[1])  
        return x  
    
class Baidu_Spider:
    # 申明相关的属性
    def __init__(self,url):  
        self.myUrl = url + '?see_lz=1'
        self.datas = []
        self.myTool = HTML_Tool()
  
    # 初始化加载页面并将其转码储存
    def baidu_tieba(self):
        # 读取页面的原始信息
        myPage = urllib2.urlopen(self.myUrl).read()
        # 计算楼主发布内容一共有多少页
        endPage = self.page_counter(myPage.decode("gbk"))
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
        # 加载页面数据到数组中
        self.get_data(url,endPage)
        # 打开本地文件
        f = open('Baidu_Tieba.txt','w+')
        for i in range(len(self.datas)):
            myData = self.myTool.Replace_Char(self.datas[i].encode('gbk'))
            f.write(myData)
        f.close()

    # 获取页面源码并将其存储到数组中
    def get_data(self,url,endPage):
        url = url + '&pn='
        for i in range(1,endPage+1):
            print u'正在下载第' + str(i) + u'个网页'
            myPage = urllib2.urlopen(url + str(i)).read()
            # 将myPage中的html代码处理并存储到datas里面
            self.deal_data(myPage.decode('gbk'))
            

    # 将内容从页面代码中抠出来
    def deal_data(self,myPage):
        myItems = re.findall('id="post_content.*?>(.*?)</div>',myPage,re.S)
        for item in myItems:
            self.datas.append(item.replace("\n",""))



#-------- 程序入口处 ------------------
print u"""#---------------------------------------
#   程序：百度贴吧爬虫
#   版本：0.3
#   作者：andrew9tech
#   日期：2014-11-28
#   语言：Python 2.7
#   操作：输入网址后自动只看楼主并保存到本地文件
#   功能：将楼主发布的内容打包txt存储到本地。
#---------------------------------------
"""

# 以某小说贴吧为例子
# bdurl = 'http://tieba.baidu.com/p/2296712428?see_lz=1&pn=1'

print u'例如：http://tieba.baidu.com/p/2296712428'
print u'请输入贴吧的地址：'
bdurl = str(raw_input(u' ')) 

 

#调用
mySpider = Baidu_Spider(bdurl)
mySpider.baidu_tieba()
