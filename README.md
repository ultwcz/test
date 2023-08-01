# git command learning repo

## initialize
Create a New file README.md

> git init

### add file to workspace
> git add README.md  

### commit
> git commit -m "xxx"

## link remote repository
> git remote add origin xxx@xxx

## push code
> git push origin master(branch name)




## remote
create local branch
> git branch 'branch's name'

delete local branch
> git branch -d 'branch's name'

create remote branch
** after create local branch
> git checkout -b 'branch'name'
git push origin 'branch's name'

delete remote branch
> git push origin --delete 'branch's name'

## Modified commited info such as author
> git rebase -i HEAD~5
modified pick to edit 'wq' save & exit

> git commit --amend --author="name <email@xxx.com>" --no-edit

