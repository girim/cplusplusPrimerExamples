set nocompatible              " be iMproved, required
filetype off                  " required



set backspace=indent,eol,start
set history=1000           "keep 1000 lines of command line history"
set number                 "to display line numbers"
set ruler                  "show the curser position all the time
set showcmd                "display incomplete commands
set incsearch              "do increamental search
set splitright             "Vertical spilts use right half of the screen
set tildeop                "use ~ to toggle case as an operator, not a motion
set hlsearch

" Tab settings
set expandtab
set tabstop=4
set softtabstop=4      " default to 2 spaces for the soft tab
set shiftwidth=2       " for when <TAB> is pressed at the beginning of a line

" Set the colorscheme
syntax enable


set t_Co=256
set showmode
set smartindent
set laststatus=2

let g:airline_theme='dark'

filetype plugin indent on    " required

" set file path for YCM conf file
let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'


" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim

" let Vundle manage Vundle, required
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'jiangmiao/auto-pairs'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'scrooloose/nerdtree'
Plugin 'altercation/vim-colors-solarized'
Plugin 'flazz/vim-colorschemes'
Plugin 'taglist.vim'
Plugin 'kien/ctrlp.vim'
Plugin 'ervandew/supertab'
Plugin 'yggdroot/indentline'
Plugin 'tpope/vim-fugitive'
Plugin 'scrooloose/syntastic'
Plugin 'Conque-GDB'
Plugin 'c.vim'
Plugin 'octol/vim-cpp-enhanced-highlight'

" All of your Plugins must be added before the following line
call vundle#end()

let g:solarized_termcolors=256  
set background=light 

let g:indentLine_enabled = 0
let c_no_curly_error=1
let g:cpp_class_scope_highlight = 1


highlight Search     ctermfg=Black      ctermbg=Yellow     cterm=NONE
highlight Comment    ctermfg=Blue


" colorscheme  dark

" To ignore plugin indent changes, instead use:
"filetype plugin on
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
