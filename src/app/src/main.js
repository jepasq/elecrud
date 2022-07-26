const { app, BrowserWindow, ipcMain, nativeTheme } = require('electron');
const path = require('path')
const chore = require('./chore')

const createWindow = () => {
  const win = new BrowserWindow({
      width: 800,
      height: 600,
      webPreferences: {
	  nodeIntegration: true, // is default value after Electron v5
	  contextIsolation: true, // protect against prototype pollution
	  enableRemoteModule: false, // turn off remote
	  preload: path.join(__dirname, 'preload.js'),
      }
  })

    win.loadFile('index.html')
//    win.webContents.openDevTools();

    
    ipcMain.handle('dark-mode:toggle', () => {
    if (nativeTheme.shouldUseDarkColors) {
      nativeTheme.themeSource = 'light'
    } else {
      nativeTheme.themeSource = 'dark'
    }
    return nativeTheme.shouldUseDarkColors
  })

  ipcMain.handle('dark-mode:system', () => {
    nativeTheme.themeSource = 'system'
  })
}

app.whenReady().then(() => {
    createWindow()

    app.on('activate', () => {
	if (BrowserWindow.getAllWindows().length === 0)
	    createWindow();
    })

    let today = new Date().toLocaleDateString();
    let c = chore.Chore.new(today);
    console.log(today);
    
})

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') app.quit()
})
