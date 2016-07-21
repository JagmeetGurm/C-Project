using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using UsedGadgetsSale.Models;
using System.Web.ModelBinding;
namespace UsedGadgetsSale
{
    public partial class GadgetDetails : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }


        public IQueryable<Gadget> GetGadget([QueryString("gadgetID")] int? gadgetId)
        {
            var _db = new UsedGadgetsSale.Models.GadgetContext();
            IQueryable<Gadget> query = _db.Gadgets;
            if (gadgetId.HasValue && gadgetId > 0)
            {
                query = query.Where(p => p.GadgetID == gadgetId);
            }
            else
            {
                query = null;
            }
            return query;
        }
    }
}