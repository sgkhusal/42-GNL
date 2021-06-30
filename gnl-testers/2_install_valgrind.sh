# INSTALL VALGRIND
cd ~
rm -rf $HOME/.brew &&
	git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew &&
	echo 'export PATH=$HOME/.brew/bin:$PATH' >>$HOME/.zshrc &&
	source $HOME/.zshrc &&
	brew update
curl https://raw.githubusercontent.com/sowson/valgrind/master/valgrind.rb >valgrind.rb
brew install --HEAD valgrind.rb