# Guardfile
#
guard :shell do
  watch(/configure\.ac/) do
    system("./bootstrap")
  end
  watch(/Makefile\.am/) do
    system("make clean")
    system("./configure --with-coverage")
  end
  watch(/(src|test)\/(.+)\.(c|h)/) do
    system("make check || cat test/*_tests.log")
  end
end
