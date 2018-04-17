# code-review-homework-1

经过第一堂课「Code Review」的学习，您一定得到了很多知识。  
要将知识化为自己的技能，则是需要「刻意练习」。  
而一个人的思考是不完整的，借助团队的力量生成自己的代码评审原则，将更能帮助你应对未来的工作场景。  
所以，赶紧和你的团队，一起来进行练习吧。

## 内容
1. 请和您的小组一起用三个步骤来重新分析代码评审和写代码：

    1.  明确效果
    2.  分析对象
    3. 确立原则

2. 用结果所产出的原则来评审所有人的代码 。   
3. 根据代码评审的结果，对之前的代码进行修改。

## 提交方式
当您完成代码评审，修改代码之后，请将代码提交到您之前Fork了的仓库中，然后发一个Pull Request到[code-review-task-1](https://github.com/rhrgf/code-review-task-1)


更改的代码如下：
1、更改命名方式
2、添加注释
3、异常处理

# -*- coding:utf-8 -*-
try:
    f = open("words.txt",'r')
    char = f.read(1);


    words = ''; 
    words_list = [];  #存储由空格或换行隔开的单词
    while char != '':
        if (char != ' ' and char != '\n'):
            words += char;
            char = f.read(1);
        else:
            words_list.append(words);
            words = '';
            char = f.read(1);
    words_list.append(words);

    words_num = 0;  #单词的数量
    appeared_words = [];  #遍历时以出现过的单词
    i = 0;
    while (i != len(words_list)):
        if (words_list[i] in appeared_words):
            i += 1;
        else:
            words_num = words_list.count(words_list[i]);
            words_num = str(words_num);
            print (words_list[i] + ' ' + words_num);
            appeared_words.append(words_list[i]);
            i +=1;
except:
    print('文件错误！');
finally:
    f.close();
