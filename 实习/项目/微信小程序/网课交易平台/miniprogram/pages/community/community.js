// pages/community/community.js
const db = wx.cloud.database()
const app = getApp()

Page({

  /**
   * 页面的初始数据
   */
  data: {
    username: "Cony",
    commodity: "Air Jodan",
    likeIconURL: '/images/like.png',
    clickLike: false
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  },

  /**Click like */
  clickLike: function () {
    if (!this.data.clickLike) {
      this.setData({
        likeIconURL: '/images/likeClicked.png',
        clickLike: true
      })
      this.onLoad
    } else {
      this.setData({
        likeIconURL: '/images/like.png',
        clickLike: false
      })
      this.onLoad
    }
  }
})