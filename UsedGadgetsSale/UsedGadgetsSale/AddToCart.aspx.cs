using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;
using UsedGadgetsSale.Logic;


namespace UsedGadgetsSale
{
    public partial class AddToCart : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string rawId = Request.QueryString["GadgetID"];
            int gadgetId;
            if (!String.IsNullOrEmpty(rawId) && int.TryParse(rawId, out gadgetId))
            {
                using (ShoppingCartActions usersShoppingCart = new ShoppingCartActions())
                {
                    usersShoppingCart.AddToCart(Convert.ToInt16(rawId));
                }

            }
            else
            {
                Debug.Fail("ERROR : We should never get to AddToCart.aspx without a GadgetId.");
                throw new Exception("ERROR : It is illegal to load AddToCart.aspx without setting a GadgetId.");
            }
            Response.Redirect("ShoppingCart.aspx");
        }
    }
}