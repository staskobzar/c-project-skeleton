# Guardfile
#
guard :shell do
  watch(/configure\.ac/) do
    `./bootstrap`
  end
  watch(/Makefile\.am/) do
    `./configure`
  end
  watch(/(.+)\.(c|h)/) do
    `make check`
  end
end
