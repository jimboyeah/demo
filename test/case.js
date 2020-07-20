module.exports = {
  'Demo test': function (browser) {
    browser
      .url('http://localhost:8080/')
      .waitForElementVisible('body')
      .assert.titleContains('vue3rd')
      .waitForElementVisible('.home', 3000)
      .assert.urlContains('/')
      .assert.visible('input[type=search]')
      .setValue('input[type=search]', 'nightwatch')
      .assert.visible('button[type=submit]')
      .click('button[type=submit]')
      .setValue('input[type=search]', 'nightwatch & selenium')
      .assert.containsText('.home', 'Home')
      .end();
  }
};
