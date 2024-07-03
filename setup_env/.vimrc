call plug#begin('~/.vim/plugged')

" Plugins
Plug 'tpope/vim-sensible'
Plug 'tpope/vim-commentary'
Plug 'preservim/nerdtree'
Plug 'itchyny/lightline.vim'
Plug 'catppuccin/vim', { 'as': 'catppuccin' }
Plug 'prabirshrestha/vim-lsp'
Plug 'mattn/vim-lsp-settings'
Plug 'prabirshrestha/asyncomplete.vim'
Plug 'ghifarit53/tokyonight-vim'
Plug 'AlessandroYorba/Alduin'
Plug 'wojciechkepka/vim-github-dark'
Plug 'junegunn/fzf.vim'
call plug#end()

" Plugin configurations
set termguicolors
set laststatus=2

" Lightline configuration
let g:lightline = {
      \ 'colorscheme': 'tokyonight',
      \ }

" Tokyonight configuration
let g:tokyonight_style = 'night' " available: night, storm
let g:tokyonight_enable_italic = 1
" commentary plugin
filetype plugin indent on



" Set the color scheme
colorscheme ghdark 

" Additional settings
set number
set rnu

nmap <space>gb :Ex<CR>
nnoremap <C-n> :NERDTreeToggle<CR>
nnoremap <C-s> :wa<CR>

" Handle the mouse
set mouse=a
