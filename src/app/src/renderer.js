/*
require('popper.js');
require('bootstrap');
*/

$('#toggle-dark-mode').on ('click', (event) => {
    const isDarkMode = window.darkMode.toggle();
    document.getElementById('theme-source').innerHTML=isDarkMode?'Dark':'Light';
});

$('#reset-to-system').on ('click', (event) => {
    console.log("Reset to system clicked");
    window.darkMode.system()
    document.getElementById('theme-source').innerHTML = 'System'
});


$('#btn-preferences').on ('click', (event) => {
    console.log("Show preferences dialog");
    $('#myModal').show({backdrop: 'static'})
});

$('#myModal .close').on ('click', (event) => {
    $('#myModal').hide()
});


